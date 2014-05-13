Arduino implementation of Protothreads version 1.4.01
-----------------------------------------------------

Protothreads are extremely lightweight stackless threads designed for severely
memory constrained systems, such as small embedded systems or wireless sensor
network nodes.

Protothreads provide linear code execution for event-driven systems
implemented in C. Protothreads can be used with or without an underlying
operating system to provide blocking event-handlers.

Protothreads provide sequential flow of control without complex state machines
or full multi-threading. 


Main features:

* Very small RAM overhead - only two bytes per protothread and no extra stacks
* Highly portable - the protothreads library is 100% pure C and no architecture
  specific assembly code
* Can be used with or without an OS
* Provides blocking wait without full multi-threading or stack-switching
* Freely available under a BSD-like open source license 


Related links:

Protothreads: 
http://www.sics.se/~adam/pt/index.html

Download of original Protothreads on which this version is based on:
http://www.sics.se/~adam/pt/download.html

Publications:
http://www.sics.se/~adam/pt/publications.html

Documentation:
http://www.sics.se/~adam/pt/pt-1.4-refman/

Protothreads has been developed by Adam Dunkels
http://www.sics.se/~adam/

The original Protothreads implementation by Adam Dunkels as been adopted
to the Arduino platform and is maintained by Benjamin Soelberg.

The Arduino "implementation" of Protothreads is based on version 1.4 of
the original Protothreads.

email benjamin.soelberg@gmail.com
blog  http://www.kukkuk.dk
www   http://www.javadesign.dk
