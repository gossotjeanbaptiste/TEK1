import matplotlib.pyplot as plt
import numpy as np

# --- Définition plus détaillée des points du contour de l'Android ---
points_android = np.array([
    # Tête (courbe supérieure)
    (0.5, 0.95), (0.45, 1.0), (0.4, 1.02), (0.35, 1.0), (0.3, 0.95),
    (0.28, 0.9), (0.26, 0.85), (0.25, 0.8), (0.25, 0.75),
    (0.26, 0.7), (0.28, 0.65), (0.3, 0.6),
    (0.7, 0.6), (0.72, 0.65), (0.74, 0.7), (0.75, 0.75),
    (0.75, 0.8), (0.74, 0.85), (0.72, 0.9), (0.7, 0.95),
    (0.65, 1.0), (0.6, 1.02), (0.55, 1.0),
    # Corps
    (0.3, 0.6), (0.25, 0.5), (0.25, 0.3), (0.3, 0.2),
    (0.7, 0.2), (0.75, 0.3), (0.75, 0.5), (0.7, 0.6),
    # Bras gauche
    (0.2, 0.55), (0.15, 0.5), (0.12, 0.4), (0.15, 0.3), (0.2, 0.25),
    # Bras droit
    (0.8, 0.55), (0.85, 0.5), (0.88, 0.4), (0.85, 0.3), (0.8, 0.25),
    # Jambe gauche
    (0.32, 0.2), (0.3, 0.15), (0.3, 0.05), (0.35, 0.0), (0.4, 0.05), (0.4, 0.15), (0.38, 0.2),
    # Jambe droite
    (0.68, 0.2), (0.65, 0.15), (0.65, 0.05), (0.6, 0.0), (0.55, 0.05), (0.55, 0.15), (0.62, 0.2),
    # Antennes
    (0.4, 1.05), (0.38, 1.15), (0.42, 1.15),
    (0.6, 1.05), (0.58, 1.15), (0.62, 1.15)
])

# --- Création de la figure et des axes ---
fig, ax = plt.subplots(figsize=(8, 8))
ax.set_aspect('equal', adjustable='box')
ax.axis('off')

# --- Tracé du contour de l'Android ---
ax.plot(points_android[:, 0], points_android[:, 1], 'g-', linewidth=2)

# --- Positionnement des flèches autour du contour ---
num_fleches = 30
indices_fleches = np.linspace(0, len(points_android) - 1, num_fleches, endpoint=False, dtype=int)

taille_fleche = 0.015

for i in indices_fleches:
    x1, y1 = points_android[i]
    x2_index = (i + 1) % len(points_android)
    x2, y2 = points_android[x2_index]

    # Calculer la direction de la flèche
    dx = x2 - x1
    dy = y2 - y1

    # Normaliser la direction
    longueur = np.sqrt(dx**2 + dy**2)
    if longueur > 0:
        dx_norm = dx / longueur
        dy_norm = dy / longueur
        ax.arrow(x1 + dx_norm * taille_fleche * 2,
                 y1 + dy_norm * taille_fleche * 2,
                 -dx_norm * taille_fleche,
                 -dy_norm * taille_fleche,
                 head_width=taille_fleche * 1.5,
                 head_length=taille_fleche * 2,
                 fc='r',
                 ec='r',
                 length_includes_head=True)

# --- Titre et limites ---
plt.title("Tracé du logo Android avec des flèches en boucle")
plt.xlim(0, 1)
plt.ylim(0, 1.2)

# --- Exportation en PNG ---
plt.savefig("android_flèches.png")

# --- Affichage du résultat (optionnel, commenter si vous voulez juste l'export) ---
# plt.show()
