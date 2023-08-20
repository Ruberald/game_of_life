project('game_of_life', 'CPP')

sources = files(
  'src/main.cpp',
  'src/game.cpp',
  'src/display.cpp'
  )
incdir = include_directories('headers')

deps = [dependency('sfml-window'), dependency('sfml-graphics'), dependency('sfml-system')]

executable('game_of_life', sources, include_directories: incdir, dependencies : deps)

