**ZeroMQ with Boost under VisualStudio 2015**


This repository contains a VisualStudio 2015 Solution with four projects:

a) **ZeroMQ Client/Server example** (server and client projects)

b) **ZeroMQ Publish/Subscribe example** (server and client projects)

The PubSub example uses the <a href="http://www.boost.org/" target="_blank">boost libraries</a> for text parsing.

**Compiling**

To compile the projects some preparations are needed:

a) Get the <a href="https://github.com/zeromq/zeromq4-x" target="_blank"> ZeroMQ v4 sources</a> from GitHub and compile it by using the prepared solution under *builds/msvc*
b) Insert the paths to ZeroMQ includes and the compiled ZeroMQ-Lib. I'd recommend to create a new environment variable called ZMQ_HOME which should point to the
GitHub-directory where the sources of 0MQ are located. Here's how it looks like on my machine:

