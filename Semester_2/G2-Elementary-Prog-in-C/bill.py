import networkx as nx
import matplotlib.pyplot as plt

# Création du graphe
G = nx.Graph()

# Définir les positions des nœuds (forme de Bill Cipher)
nodes = {
    "Bottom_Left": (0, 0),
    "Bottom_Right": (2, 0),
    "Top": (1, 3),
    "Eye": (1, 2),
    "Bowtie": (1, 1),
    "Left_Leg": (0.7, -1),
    "Right_Leg": (1.3, -1),
    "Left_Arm": (-0.5, 1.5),
    "Right_Arm": (2.5, 1.5),
    "Hat_Base": (1, 3.5),
    "Hat_Top": (1, 4),
}

# Ajouter les nœuds au graphe
G.add_nodes_from(nodes.keys())

# Définir les arêtes pour dessiner la forme de Bill
edges = [
    ("Bottom_Left", "Bottom_Right"),
    ("Bottom_Right", "Top"),
    ("Top", "Bottom_Left"),
    ("Eye", "Top"),
    ("Eye", "Bottom_Left"),
    ("Eye", "Bottom_Right"),
    ("Eye", "Bowtie"),
    ("Top", "Hat_Base"),
    ("Hat_Base", "Hat_Top"),
    ("Bottom_Left", "Left_Leg"),
    ("Bottom_Right", "Right_Leg"),
    ("Bottom_Left", "Left_Arm"),
    ("Bottom_Right", "Right_Arm")
]
G.add_edges_from(edges)

# Dessin du graphe
plt.figure(figsize=(8, 10))
nx.draw(G, nodes, with_labels=True, node_color='gold', node_size=900, font_weight='bold', edge_color='black')
plt.title("Graphe abstrait en forme de Bill Cipher", fontsize=14)
plt.axis('off')

# Sauvegarde en PNG
plt.savefig("graphe_bill_cipher.png", format='png', bbox_inches='tight')
plt.show()

print("✅ Graphe exporté en tant que 'graphe_bill_cipher.png' dans le dossier courant.")
