import QtQuick 2.15
import QtGraphicalEffects 1.15

Item {
	id: root

	property QtObject gridModel: null // C++: GameGridModel

	implicitHeight: itemGrid.implicitHeight
	implicitWidth: itemGrid.implicitWidth

	Grid {
		id: itemGrid

		columns: 3
		rows: 3

		spacing: 5

		Repeater {
			id: cellsRepeater

			model: root.gridModel

			delegate: Rectangle {
				implicitHeight: 125
				implicitWidth: 125

				color: "transparent"
				border.color: "#c3cfe0"

				Image {
					id:image

					anchors.centerIn: parent

					source: model.imageSource
					width: internal.imageSize.width
					height: internal.imageSize.height
				}

				ColorOverlay {
					anchors.fill: image
					source: image
					color: "#f1f8f6"
				}

				MouseArea {
					anchors.fill: parent

					enabled: model.isEditable

					onClicked: {
						root.gridModel.makeMove(index)
					}
				}
			}
		}

	}

	QtObject {
		id: internal

		readonly property size imageSize: Qt.size(80, 80);
	}
}
