**ZeroMQ with Boost under VisualStudio 2015**


This repository contains a VS 2015 Solution with four projects based on <a href="http://zeromq.org/" target="_blank">ZeroMQ</a> examples:

a) **ZeroMQ Client/Server example** (server and client projects)

b) **ZeroMQ Publish/Subscribe example** (server and client projects)

The PubSub example uses the <a href="http://www.boost.org/" target="_blank">boost libraries</a> for message parsing.

**Compiling**

To compile the projects you'll need to compile ZeroMQ and checkout some sources. The predefined settings in the VS-Solution will expand to several paths. So take care of putting them into these ENV-variables:

    ZMQ_HOME:        sources from zeromq/libzmq
    ZMQ_CPP_HEADERS: sources from zeromq/cppzmq
    ZMQ_LIBS:        binaries compiled from ZMQ_HOME directory
    ZMQ_LIBSODIUM:   sources from jedisct1/libsodium (IMPORTANT: libsodium must go inside the libzmq-root directory so the ZMQ-lib can be compiled with libsodium support)
    ZMQ_ZGUIDE:      sources from booksbyus/zguide 

Additionally:

* Compile *libzmq* by opening the solution under *builds/msvc/vs2015* or via batch-files under *builds/msvc/build*. As already mentioned, if you want to have libsodium support _you must checkout_ its sources inside the root directory of libzmq _before_ you compile libzmq!
* Compile *libsodium* by using the solution under *builds/msvc/vs2015* or via batch files under *builds/msvc/build*.
* Put the paths to the DLLs into their respective env variables (ZMQ_LIBS & ZMQ_LIBSODIUM)

This is how the path to **ZMQ-Sources* looks like on my machine:

<img src="http://fs5.directupload.net/images/160917/8esjgj97.png" width="746" height="217" border="3">

Here's the path to the **compiled Libsodium-binary** (notice the root directory that belongs to ZeroMQ):

<img src="http://fs5.directupload.net/images/160917/p8wc2mab.png" width="746" height="217" border="3"/> 

* Additionally insert the base path of *zguide* where the C++ helper-headers reside. This is not mandatory but these header files contain many helpful functions & macros.

<img src="http://fs5.directupload.net/images/160917/fzw2fowk.png" width="746" height="217" border="3">

* And this is how we reference them in our projects:

<img src="http://fs5.directupload.net/images/160917/fes5mm3n.png" />

* ZMQ-Binaries have their own env-variable, of course. Depending on what architecture and toolset are being used the predefined variables in VS2015 will expand to their x86/x64 & Debug/Release versions.

<img src="http://fs5.directupload.net/images/160917/8ekhuyv9.png" width="746" height="217" border="3"/>

* Here's how it looks like in VS-Project Properties:

<img src="http://fs5.directupload.net/images/160917/lw8pk973.png" width="776" height="366" border="3">

* The ZeroMQ **static library** is also in the list of additional dependencies.

<img src="http://fs1.directupload.net/images/150802/gfadnb6p.png" width="600" height="200" border="3">

* To properly run client/server apps based on ZeroMQ we need the *ZeroMQ-DLL* for **dynamic binding**. There's already a *Post-Build-Event* that'll be executed after each successful build:

<img src="http://fs5.directupload.net/images/160917/zgmvvgm9.png" width="786" height="404" border="3"/>


Now, compile the sources and let ZeroMQ fly :smile:

<img src="http://fs2.directupload.net/images/150802/iuea28nd.png">

**License**

[MIT](https://github.com/brakmic/ZeroMQ/blob/master/LICENSE)
