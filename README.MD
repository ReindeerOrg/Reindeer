WIP programming language for digital circuit design

# Requirements to build
- C compiler
- meson
- ninja

# Setting things up
```sh
git clone https://github.com/ReindeerOrg/Reindeer.git
cd Reindeer
meson builddir
cd builddir
```

# Building it
Use the following code to modify 
```sh
ninja
```

# Contribution guide
- Check ``demo.rd`` for demo syntax
- Dont modify readme
- Create a pull request if u want to add code
- Use git. Dont use the drag and drop feature of github
- This is not a library so when we define a function then we name it ``func`` instead of something like ``reindeer_func`` because we are not making a library
- Create an issue if u encounter any bug
- Read the header files to know how to use a particular function
- Check meson.build in the root directory. U will find code like the following
  ```python
    executable(
        'test_utils.elf',
        sources: ['test_utils.c'], 
        include_directories:[include1],
        link_with: [reindeer]
    )
    ```
    This means that ``./test_utils.elf`` is an exe that u can run from cmd. We use it to test various components

- If u add new c src files then then dont forget to add it to the relevent lisr in ``Reindeer/meson.build``
- Let's say we want to include the header file ``Reindeer/utils/utils.hpp`` then we just have to write ``#include "utils/utils.hpp"`` because we consider ``Reindeer`` as include directory
- If u are using clangd then u can create a .clangd file at base directory and add the following for proper intellisense
    ```
    CompileFlags: # Tweak the parse settings, example directory given to show format
    Add:
        - "--include-directory=/home/saptak/Desktop/project/Reindeer/Reindeer/"
    ```
    Dont forget to modify the include directory to match that of your computer 
- Follow the directory structure if u create a new file/folder