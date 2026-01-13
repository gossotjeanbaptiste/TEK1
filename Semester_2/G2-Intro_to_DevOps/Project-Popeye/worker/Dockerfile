# Étape 1 : Compilation du projet avec Maven
FROM maven:3.9.6-eclipse-temurin-21-alpine AS builder  

# Définition du répertoire de travail de docker
WORKDIR /app  

# Copie du fichier de configuration Maven
COPY pom.xml .  

# Résolution des dépendances Maven pour éviter de les re-télécharger à chaque build
RUN mvn dependency:resolve  

COPY src/ ./src  

RUN mvn package -DskipTests  

# Étape 2 : Exécution de l'application avec une image légère Java
FROM eclipse-temurin:21-jre-alpine  

# Définition du répertoire de travail de docker
WORKDIR /app

COPY --from=builder /app/target/worker-jar-with-dependencies.jar worker.jar  

# Commande pour exécuter le service Worker en Java
CMD ["java", "-jar", "worker.jar"]
