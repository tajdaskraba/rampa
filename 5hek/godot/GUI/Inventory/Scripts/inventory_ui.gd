class_name InventoryUI extends Control

const INVENTORY_SLOT = preload("res://GUI/Inventory/inventory_slot.tscn")

@onready var data : InventoryData = PlayerManager.INVENTORY_DATA

@onready var inventory_overlay: CanvasLayer = $"../../.."

func _ready() -> void:
	data.inventory_changed.connect(update_inventory)
	update_inventory()

	
func clear_inventory() -> void:
	for c in get_children():
		c.queue_free()
		

func update_inventory() -> void:
	clear_inventory()
	for s in data.slots:
		var new_slot = INVENTORY_SLOT.instantiate()
		add_child(new_slot)
		new_slot.slot_data = s
