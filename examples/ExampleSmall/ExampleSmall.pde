/**
 * This is a very small example that shows how to use
 * protothreads. The program consists of two protothreads that wait
 * for each other to toggle a variable.
 */

/* We must always include pt.h in our protothreads code. */
#include "pt.h"

/* Two flags that the two protothread functions use. */
static int protothread1_flag, protothread2_flag;

/* protothread state variables, one for each ptorothread. */
static struct pt pt1, pt2;

/**
 * The first protothread function. A protothread function must always
 * return an integer, but must never explicitly return - returning is
 * performed inside the protothread statements.
 *
 * The protothread function is driven by the main loop further down in
 * the code.
 */
static int protothread1(struct pt *pt)
{
  /* A protothread function must begin with PT_BEGIN() which takes a
     pointer to a struct pt. */
  PT_BEGIN(pt);

  /* We loop forever here. */
  while(1) {
    /* Wait until the other protothread has set its flag. */
    PT_WAIT_UNTIL(pt, protothread2_flag != 0);
    Serial.println("Protothread 1 running");

    /* We then reset the other protothread's flag, and set our own
       flag so that the other protothread can run. */
    protothread2_flag = 0;
    protothread1_flag = 1;

    /* And we loop. */
  }

  /* All protothread functions must end with PT_END() which takes a
     pointer to a struct pt. */
  PT_END(pt);
}

/**
 * The second protothread function.
 * This one is almost the same as the first one.
 */
static int protothread2(struct pt *pt)
{
  PT_BEGIN(pt);

  while(1) {
    /* Let the other protothread run. */
    protothread2_flag = 1;

    /* Wait until the other protothread has set its flag. */
    PT_WAIT_UNTIL(pt, protothread1_flag != 0);
    Serial.println("Protothread 2 running");
    
    /* We then reset the other protothread's flag. */
    protothread1_flag = 0;

    /* And we loop. */
  }
  PT_END(pt);
}

/**
 * setup() is where the protothreads are initialized.
 * The state variables pt1 and pt2 holdthe state of the two protothreads.
 */
void setup() 
{ 
  /* Initialize the protothread state variables with PT_INIT(). */
  PT_INIT(&pt1);
  PT_INIT(&pt2);

  Serial.begin(9600);
} 
 
/**
 * Finally, we have the main loop.
 * This is where the protothreads are scheduled. 
 */
void loop() 
{ 
  /*
   * We schedule the two protothreads by repeatedly calling their
   * protothread functions and passing a pointer to the protothread
   * state variables as arguments.
   */
  protothread1(&pt1);
  protothread2(&pt2);
}
