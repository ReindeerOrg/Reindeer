project('Reindeer', 'c', version: '0.1.0')

include1 = include_directories('./Reindeer')

add_project_arguments(language: 'c')

subdir('Reindeer')

reindeer=static_library(
    'reindeer',
    include_directories:[include1],
    sources:utils_str+lexer_src+ast_src+parser_src,
    install:true
)

pkg = import('pkgconfig')
headers = ['.'] # subdirectories of ${prefix}/${includedir} to add to header path
pkg.generate(libraries : reindeer,
             subdirs : headers,
             version : '0.1.0',
             name : 'Reindeer',
             filebase : 'reindeer',
             description : 'A language to create programming languages')

executable(
    'test_utils.elf',
    sources: ['test_utils.c'], 
    include_directories:[include1],
    link_with: [reindeer]
)
