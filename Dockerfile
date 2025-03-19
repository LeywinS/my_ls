# Utiliser Debian 10 comme base
FROM debian:10

# Installer GCC et Make
RUN apt update && apt install -y gcc make

# Définir le répertoire de travail
WORKDIR /my_ls

# Copier tout le contenu du projet dans le conteneur
COPY . .

# Vérifier que les fichiers sont bien copiés
RUN ls -la

# Compiler my_ls
RUN make

# Définir la commande par défaut du conteneur
CMD ["./my_ls"]
