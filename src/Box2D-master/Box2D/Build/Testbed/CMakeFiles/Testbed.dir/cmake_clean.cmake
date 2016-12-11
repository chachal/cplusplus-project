file(REMOVE_RECURSE
  "Testbed.pdb"
  "Testbed"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/Testbed.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
