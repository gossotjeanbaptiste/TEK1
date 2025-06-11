# Utilisation d'une image Python 3.9 légère
FROM python:3.9-slim  

# Définition du répertoire de travail de docker
WORKDIR /app  

# Copie du fichier requirements.txt pour installer les dépendances
COPY requirements.txt .  

# Installation des dépendances nécessaires (Flask, Gunicorn(qui est en serveur web), etc.)
RUN pip install --no-cache-dir -r requirements.txt && pip install gunicorn  

COPY . .  

EXPOSE 80  

# Commande pour démarrer l'application Flask avec Gunicorn (wsgi = Web Server Gateway Interface)
CMD ["gunicorn", "--bind", "0.0.0.0:80", "wsgi:app"]
