cmake_minimum_required(VERSION 3.30)
project(ContactManager C)

set(CMAKE_C_STANDARD 23)

add_executable(ContactManager
        src/main.c
        src/contacts.c
)
