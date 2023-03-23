cmake_minimum_required(VERSION 3.10)
project(university_db)
set(FILES person.cpp student.cpp university.cpp addons.cpp)

add_executable(${PROJECT_NAME} main.cpp ${FILES})