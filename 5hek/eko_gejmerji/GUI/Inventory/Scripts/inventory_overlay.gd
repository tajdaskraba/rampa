extends CanvasLayer

var item_description: Label

func _ready() -> void:
	item_description = $Control/ItemDescription

func update_item_description(new_text: String) -> void:
	if item_description == null:
		return
	item_description.text = new_text
