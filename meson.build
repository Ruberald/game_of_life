project('game_of_life', 'CPP')

incdir = include_directories('headers')

deps = [dependency('sfml-window'), dependency('sfml-graphics'), dependency('sfml-system')]

executable('game_of_life', 'src/main.cpp', include_directories: incdir, dependencies : deps)

