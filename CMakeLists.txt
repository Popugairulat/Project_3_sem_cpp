cmake_minimum_required(VERSION 3.10) 
project(Saver)                   

set(CMAKE_CXX_STANDARD 17)          
#ищем SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)


set(SOURCES
    main.cpp
    buttons.cpp
    class.cpp
    functions.cpp
    visual.cpp
    )


set(HEADERS
    buttons.h
    class.h
    functions.h
    visual.h
)
#SFML
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)

#картинки
file(GLOB PNG_FILES Pictures/*.png)  

#шрифт
file(COPY ${PNG_FILES} DESTINATION ${CMAKE_BINARY_DIR}/Pictures) 
set(FONT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Roboto-Black.ttf")
configure_file(${FONT_PATH} ${CMAKE_CURRENT_BINARY_DIR}/Roboto-Black.ttf COPYONLY)

#текстовый файл
file(GLOB TXT_FILES Pictures/*.txt)
file(COPY ${TXT_FILES} DESTINATION ${CMAKE_BINARY_DIR}/Pictures)