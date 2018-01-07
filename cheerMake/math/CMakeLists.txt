aux_source_directory(. MCHEER_LIB_SRCS)
add_library(MCheer ${MCHEER_LIB_SRCS})

install(TARGETS MCheer DESTINATION bin)
install(FILES mcheer.h DESTINATION include)
