# Utilisation de Node.js version 21 basée sur Alpine
FROM node:20-alpine  

WORKDIR /app  

# Copie du fichier package.json pour installer les dépendances
COPY package.json ./  

# Installation des dépendances sans les packages inutiles pour la production
RUN npm install --only=production  

COPY . .  

EXPOSE 80  

# Commande pour démarrer le serveur Node.js
CMD ["node", "server.js"]