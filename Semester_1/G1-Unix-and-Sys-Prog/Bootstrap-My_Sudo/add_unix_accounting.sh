#!/bin/bash

# Create users
useradd toto
useradd tata
useradd tutu

# Set passwords for users
echo "toto:[insérer mot de passe]" | chpasswd
echo "tata:[insérer mot de passe]" | chpasswd
echo "tutu:[insérer mot de passe]" | chpasswd

# Create groups
groupadd pedago
groupadd student

# Assign users to groups
usermod -aG student toto
usermod -aG pedago tata
usermod -aG student,pedago tutu

# If it's been executed correctly
getent passwd
groups toto
groups tata
groups tutu