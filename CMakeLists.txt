project( swarm-experiments )
cmake_minimum_required( VERSION 2.6 )
set ( CMAKE_BUILD_TYPE Release )
add_definitions ( -Wall )
find_package ( Qt4 REQUIRED )
include ( ${QT_USE_FILE} )
include_directories (
	${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}
	${QT_QTCORE_INCLUDE_DIR} ${QT_QTGUI_INCLUDE_DIR} ${QT_QTCORE_INCLUDE_DIR} ${QT_QTGUI_INCLUDE_DIR} ${QT_QTOPENGL_INCLUDE_DIR}
	)
set ( swarm-experiments_HDRS
	bird.h
	rand.h
	)

set ( swarm-experiments_SRCS
	main.cpp
	mainwindow.cpp
	scene.cpp
	bird.cpp
	rand.cpp
	settings.cpp
	view.cpp
	)

set ( swarm-experiments_UIS
	settings.ui
	)
QT4_WRAP_UI(UIS ${swarm-experiments_UIS})

set ( swarm-experiments_MOCS
	mainwindow.h
	scene.h
	settings.h
	view.h
	)
QT4_WRAP_CPP(MOCS ${swarm-experiments_MOCS})

add_executable ( swarm-experiments ${swarm-experiments_SRCS} ${UIS} ${RSCS} ${TRS} ${MOCS} )
target_link_libraries ( swarm-experiments  ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTOPENGL_LIBRARY} )
