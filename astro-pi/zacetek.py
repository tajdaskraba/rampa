# Uvoz knjiznic
from sense_hat import SenseHat
from time import sleep

# Nastavitev senzorja HAT
sense = SenseHat()
sense.set_rotation(270, False)

# Nastavitev barvnega senzorja
sense.color.gain = 60 # Set the sensitivity of the sensor
sense.color.integration_cycles = 64 # The interval at which the reading will be taken

# Dodaj barvne spremenljivke

rgb = sense.color # pridobi barvo iz senzorja

c = (rgb.red, rgb.green, rgb.blue) # barva ocesa
s = (139, 69, 19) # rjava
a = (255, 255, 255) # bela
v = (255, 0, 0) # rdeca
t = (255, 140, 0) # oranzna
q = (255, 255, 0) # rumena
m = (34, 139, 34) # zelena
h = (0, 255, 255) # modra
z = (153, 50, 204) # vijolicna
y = (255, 20, 147) # roza

# Dodaj sliko
image = [
    a, a, v, v, t, a, a, a,
    a, v, v, t, t, q, a, a,
    v, c, t, t, q, q, m, a,
    v, t, t, q, q, m, m, h,
    s, s, q, s, s, m, s, h,
    a, a, a, a, a, a, a, z,
    a, a, a, a, y, a, a, z,
    a, a, a, a, a, y, z, a]

# Prikazi sliko
sense.set_pixels(image)