cmake_minimum_required(VERSION 3.5)

project("Tic-Tac-Toe Game" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(headers
        src/GuiModel.h
        src/AbstractGameModeFactory.h
        src/Board.h
        src/ComputerModeFactory.h
        src/ComputerPlayer.h
        src/GameController.h
        src/GameManager.h
        src/GameModeEnum.h
        src/HumanPlayer.h
        src/Player.h
        src/PlayerMarkEnum.h
        src/PlayersModeFactory.h
        src/models/GameGridModel.h
        src/models/WinnerInfoModel.h
        src/game_utils.h
)

set(sources
        src/GuiModel.cpp
        src/main.cpp
        src/Board.cpp
        src/ComputerModeFactory.cpp
        src/ComputerPlayer.cpp
        src/GameController.cpp
        src/GameManager.cpp
        src/HumanPlayer.cpp
        src/Player.cpp
        src/PlayersModeFactory.cpp
        src/models/GameGridModel.cpp
        src/models/WinnerInfoModel.cpp
        src/game_utils.cpp
)

set(qml
        qml/GameModeComboBox.qml
        qml/GameGrid.qml
        qml/MainWindow.qml
)

set(resources
        tic-tac-toe.qrc
        res/images/images.qrc
)

find_package(Qt5 COMPONENTS Core Gui Qml Quick QuickControls2 REQUIRED)

add_executable(TicTacToeGame WIN32 ${headers} ${sources} ${qml} ${resources})

target_link_libraries(TicTacToeGame
	Qt::Core
	Qt::Gui
	Qt::Qml
	Qt::Quick
	Qt::QuickControls2
)
