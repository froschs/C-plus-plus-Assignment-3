### Assignment 3
##### What aside from executable binaries can we make
Something to consider is that we have a lot of important logic baked into assignment 2 regarding how our config file is being read. 
It would be best if all of our future applications could read our config file with out having to copy the code directly. One major concern
is that if we duplicate code and then need to make a change to that logic in a systemic way we might have to open a number of projects and
make a series of changes. That sounds painful to me!

In the world of C++ it is trivial to combine code into a library as a binary and access it in any other application. To do this we need to 
employ some new incantations in cmake.

First lets create a library that has a single function which carries this signature.
```
string* read_config(string config_file_path);
```
A signature is a unique series of identifiers that a computer can use to identify a specific function. This signature will:
- return a string pointer
- accept a string argument for a file path

The string pointer will hold the memory location of an array of strings which will hold the data within our config file.

You will need to open a file and read its contents into an array. If the tricky part doesn't slap you in the face here it is. To declare an
array we need to know its size. You have to figure out a way to identify the number of lines in the file and then create an array to hold
those values of the correct size.

I would start by building this project as a normal executable with a `main` function so you can test its inner workings. Once you are confident
that you libary works correctly you will need to rename the function to match the signature above and create a header file to expose our
function to the rest of the world. Its easy to create the header file in CLion. You should move your function prototype to the header and
include the header in your cpp file with a new include statement like `#include "./reader.h"`

Make sure that your library lives in its own namespace by wrapping your function and using statements like this
```
namespace config_reader{
	using ...
	...
}
```
You will need to do the same thing to your header file.

Finally you need to update your CMakeLists.txt to create a library instead of an executable. The line goes at the bottom of your CMakeLists.txt
and looks like this
```
add_library (<project_name> ${SOURCE_FILES})
```
replacing `<project_name>` with what is in is in the `project` line of the same file.

Next you need to test your library. To do so open the projects build directory and copy the .a file and the .h file from your project directory
to a new folder on your computer.
- Put them in the same folder and in a location that has an easy to remember path.
- Create a new project
- Open the CMakeLists.txt and edit it by adding the following lines
  ```
  project(<project>)

  include_directories( <library_path> )
  link_directories( <library_path> )

  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

  set(SOURCE_FILES main.cpp)
  add_executable(<project> ${SOURCE_FILES})
  # The library_name is the .a file without the lib prefix and extension
  target_link_libraries(<project> <library_name>)
  ```
- Once CMakeLists.txt is reloaded you should be able to `#include` the header file you created in your project and access your function as usual
by prefixing it with your `<namespace>::`
- You must give your second project a config file that you program can read and then display its contents
- Commit your lib project and driver project to seperate folders in the same repo.
  - There are two folders already in this repo you can use to create your projects inside of to help.

Good Luck :)
