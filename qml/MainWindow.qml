import QtQuick 2.15
import QtQuick.Window 2.15
import QtGraphicalEffects 1.15
import QtQuick.Controls 2.12

Window {
	id: root

	visible: true
	minimumWidth: 500
	minimumHeight: 600
	title: qsTr("Tic-Tac-Toe Game")

	property QtObject model : guiModel

	LinearGradient {
		id: background

		anchors.fill: parent

		gradient: Gradient {
			GradientStop { position: 0.0; color: "#23b7d2" }
			GradientStop { position: 1.0; color: "#5c33b2" }
		}
	}

	GameModeComboBox {
		id: modeComboBox

		anchors {
			left: parent.left
			top: parent.top
		}

		model: root.model
	}

	Text {
		id: currentTurnText

		anchors {
			horizontalCenter: itemGrid.horizontalCenter
			bottom: itemGrid.top
			bottomMargin: 20
		}

		text: internal.gridModel ? internal.gridModel.currentTurn : ""
	}

	GameGrid {
		id: itemGrid

		anchors.centerIn: parent

		gridModel: internal.gridModel

		Popup {
			id: infoPopup

			visible: !!root.model.winnerInfoModel && root.model.winnerInfoModel.visible

			anchors.centerIn: parent

			closePolicy: Popup.NoAutoClose
			contentItem: Text {
				text: root.model.winnerInfoModel ? root.model.winnerInfoModel.message : ""
			}
		}
	}

	Button {
		id: restartButton

		anchors {
			bottom: parent.bottom
			bottomMargin: 35
			horizontalCenter: parent.horizontalCenter
		}

		text: "Restart"

		onClicked: root.model.restartGame()
	}

	QtObject {
		id: internal

		readonly property QtObject gridModel: root.model.gridModel
	}
}
