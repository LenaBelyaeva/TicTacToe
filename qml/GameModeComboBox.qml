import QtQuick 2.15
import QtQuick.Controls 1.4

Item {
	id: root

	property QtObject model: null // C++: GuiModel

	implicitHeight: combo.implicitHeight
	implicitWidth: combo.implicitWidth

	ComboBox {
		id: combo

		width: 200

		currentIndex: root.model.gameMode

		model: ListModel {
			id: cbItems
			ListElement {
				text: "Computer";
			}
			ListElement {
				text: "Players";
			}
		}

		onCurrentIndexChanged: {
			root.model.gameMode = currentIndex;
		}
	}
}
