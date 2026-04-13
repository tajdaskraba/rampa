class_name InventoryData extends Resource

@export var slots : Array[ SlotData ]

signal inventory_changed

func add_item(item: ItemData, count: int = 1) -> bool:
	for s in slots:
		if s and s.item_data == item:
			s.quantity += count
			inventory_changed.emit()
			return true

	for i in slots.size():
		if slots[i] == null:
			var new = SlotData.new()
			new.item_data = item
			new.quantity = count
			slots[i] = new
			inventory_changed.emit()
			return true

	return false
