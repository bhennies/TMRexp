add_executable(RCUimpl rcu.cpp)
target_link_libraries(RCUimpl TMRexpLib)
add_test(NAME "RCUimpl" COMMAND "${BIN_PATH}/RCUimpl")

add_executable(RCUimpl_general rcu_general_purpose.cpp)
target_link_libraries(RCUimpl_general TMRexpLib)
add_test(NAME "RCUimpl_general" COMMAND "${BIN_PATH}/RCUimpl_general")

add_executable(TESTimpl test.cpp)
target_link_libraries(TESTimpl TMRexpLib)
add_test(NAME "TESTimpl" COMMAND "${BIN_PATH}/TESTimpl")