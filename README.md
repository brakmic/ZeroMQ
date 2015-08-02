**ZeroMQ with Boost under VisualStudio 2015**


This repository contains a VisualStudio 2015 Solution with four projects which are based on ZeroMQ example sources:

a) **ZeroMQ Client/Server example** (server and client projects)

b) **ZeroMQ Publish/Subscribe example** (server and client projects)

The PubSub example uses the <a href="http://www.boost.org/" target="_blank">boost libraries</a> for message parsing.

**Compiling**

To compile the projects some preparations are needed:

a) Get the <a href="https://github.com/zeromq/zeromq4-x" target="_blank">ZeroMQ v4 sources</a> from GitHub and compile it by using the prepared solution under *builds/msvc*

b) Optionally checkout the <a href="https://github.com/imatix/zguide" target="_blank">zguide-repository</a>. This repository contains, among many other useful things, a nice header file called "zhelpers.hpp" which can be used for easier handling of strings, for example.  

b) Insert the paths to ZeroMQ includes and the previously compiled ZeroMQ-Lib. I'd recommend to create a new environment variable called **ZMQ_HOM**E which should point to the
GitHub-directory where the sources of ZeroMQ are located. Here's an example from my machine:

<img src="http://fs2.directupload.net/images/150802/jpl9oru8.png" width="300" height="200" border="3">

c) Additionally insert the path to *zhelpers.hpp* for C++ via *Project-Properties/VC++ Directories*. The *zguide* contains many examples for a lot of different languages and therefore you could use similar helper-files for other languages, too. For example C if you decide to compile everything under pure C. I have to admit that the projects in this repo use a (weird?) mixture of C/C++ but this is just because I'm now more interested in the inner workings of ZeroMQ and not in language purity ("Modern C++" vs. "traditional C++" vs. "old-school C" etc.).

<img src="http://fs2.directupload.net/images/150802/wetv6ntd.png" width="600" height="200" border="3">

d) Add the path to the library (in my case it's a x64 lib-file, your architecture may differ and therefore another path/lib should be used). Here I'm using the **ZMQ_HOME** variable to point to the correct library.

<img src="http://fs2.directupload.net/images/150802/a52usgh9.png" width="600" height="200" border="3">

e) Add the library itself into the list of additional dependencies

<img src="http://fs1.directupload.net/images/150802/gfadnb6p.png" width="600" height="200" border="3">

f) To properly run client/server apps based on ZeroMQ one needs their DLL too. I'd recommend to create a Post-Build-Event which will be executed on each successful build:

<img src="http://fs1.directupload.net/images/150802/6fk2vh8y.png" width="600" height="200" border="3">

This is the command from my machine (it should be adapted regarding paths and env-vars):

*copy $(ZMQ_HOME)\bin\$(PlatformTargetAsMSBuildArchitecture)\libzmq.dll $(OutputPath)*


Now, compile the sources and let ZeroMQ fly :smile:

<img src="http://fs2.directupload.net/images/150802/iuea28nd.png">

**License**
MIT
