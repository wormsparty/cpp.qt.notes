gnometest_sources = [
  'main.cpp'
]

gtk_dep = dependency(
  'gtk4',
  version: '>= 4.11.2',
  fallback: ['gtk', 'gtk_dep'],
  default_options: [
    'introspection=disabled',
    'build-demos=false',
    'build-testsuite=false',
    'build-tests=false',
    'build-examples=false',
    'media-gstreamer=disabled',
    'print-cups=disabled',
    'default_library=static'
  ]
)

gnometest_deps = [
  gtk_dep,
]

executable('gnometest', gnometest_sources,
  dependencies: gnometest_deps,
  install: true,
)

