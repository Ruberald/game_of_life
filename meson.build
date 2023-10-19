project('game_of_life', 'CPP')

sources = files(
  'src/main.cpp',
  'src/game.cpp',
  'src/display.cpp'
  )
incdir = include_directories('headers')

if build_machine.system() == 'linux'
  deps = [dependency('sfml-window'), dependency('sfml-graphics'), dependency('sfml-system')]
elif build_machine.system() == 'windows'
  deps = [declare_dependency(link_args : ['-lsfml-window', '-lsfml-graphics', '-lsfml-system'], include_directories : 'libraries\SFML-2.5.1\include')]
  add_project_link_arguments('-L..\libraries\SFML-2.5.1\lib', language : 'CPP')
endif

executable('game_of_life', sources, include_directories: incdir, dependencies : deps)

