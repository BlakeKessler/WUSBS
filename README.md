# Wildly Unsafe Simple Build System (W.U.S.B.S.)

WUSBS is currently a simple build system for **C/C++** and the _gcc/g++_ compiler. It produces Makefiles, so _Make_ is needed to actually compile anything.  
Compatibility with other compilers is planned - primarily _clang_, but potentially for compilers for other languages as well.  
WUSBS will likely work properly on any computer running a Linux, Windows, or Mac operating system, but this has not yet been tested. It has currently only been tested on Ubuntu, but it should work on any OS that runs C++ and Make.
You could do some hacky bodging to make this WUSBS snapshot use any compilers that use similar syntax to g++, but that definitely manifests the wild unsafety alluded to by the name of the project (even clang usually doesn't work properly yet, but that will be fixed by the first stable release).  

The not all of the commands listed in [the commands file](docs/commands.txt) are implemented yet (as described or at all). They will all be either implemented or removed by the first full release.  

* Use of commands listed in that file will not crash WUSBS (including unimplemented ones).  
* Use of commands not listed in that file will crash WUSBS (because they do not exist and are not yet planned to exist). This is intended behavior.  

If you want to use this version of WUSBS for some reason, copy [WUSBS.ws](WUSBS.ws) and change the arguments of the commands until it works.  

>Initial Contributor(s):  
>
>* [Blake Kessler](https://github.com/BlakeKessler)  
<!-- >Contributor(s): [Blake Kessler](https://github.com/BlakeKessler) -->
