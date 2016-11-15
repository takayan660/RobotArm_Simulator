FILE(REMOVE_RECURSE
  "CMakeFiles/doxygen_doc"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/doxygen_doc.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
