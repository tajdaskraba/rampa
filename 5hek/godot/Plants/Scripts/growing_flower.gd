extends Node2D

# Definiramo stopnje rasti
enum StopnjaRasti { SEME, KALITEV, BRST, ROZA }

@export var cas_rasti_na_stopnjo: float = 5.0  # sekunde
@export var trenutna_stopnja: StopnjaRasti = StopnjaRasti.SEME # prva stopnja bo seme

@onready var sprite: Sprite2D = $Sprite2D
@onready var casovnik_rasti: Timer = $GrowthTimer

func _ready() -> void:
	# nastavi zacetno stanje
	posodobi_sprite()
	
	# konfiguriraj casovnik
	casovnik_rasti.wait_time = cas_rasti_na_stopnjo
	casovnik_rasti.timeout.connect(_ob_poteku_casovnika)
	casovnik_rasti.start()

func _ob_poteku_casovnika() -> void:
	rasti()

func rasti() -> void:
	# Preveri, ali lahko še raste
	if trenutna_stopnja < StopnjaRasti.ROZA:
		trenutna_stopnja += 1
		posodobi_sprite()
		print("Roža je zrastla do stopnje: ", trenutna_stopnja)
	else:
		# Popolnoma zrasla - ustavi časovnik
		casovnik_rasti.stop()
		print("Roža je popolnoma zrasla!")

func posodobi_sprite() -> void:
	# Posodobi sprite frame glede na stopnjo rasti
	sprite.frame = trenutna_stopnja
