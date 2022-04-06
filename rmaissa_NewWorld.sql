-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost
-- Généré le : mer. 06 avr. 2022 à 17:38
-- Version du serveur : 10.3.34-MariaDB-0+deb10u1
-- Version de PHP : 7.3.31-1~deb10u1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `rmaissa_NewWorld`
--

DELIMITER $$
--
-- Procédures
--
CREATE DEFINER=`rmaissa`@`localhost` PROCEDURE `insertCategorie` (IN `unLibelle` VARCHAR(50), IN `unIdRayon` INTEGER)  BEGIN
    insert into Categorie(libelle, identifiantRayon) values(unLibelle, unIdRayon);
END$$

CREATE DEFINER=`rmaissa`@`localhost` PROCEDURE `insertClient` (IN `unNom` VARCHAR(50), IN `unPrenom` VARCHAR(50), IN `unMail` VARCHAR(50), IN `unTelephone` VARCHAR(50), IN `uneAdresse` VARCHAR(50))  BEGIN
    insert into Client(nom, prenom, mail, telephone, adresse) values(unNom, unPrenom, unMail, unTelephone, uneAdresse);
END$$

CREATE DEFINER=`rmaissa`@`localhost` PROCEDURE `insertCommande` (IN `unIdCommande` INTEGER, IN `uneDateCommande` DATE, IN `uneDateRecuperation` DATE, IN `unIdClient` INTEGER, IN `unIdSemaine` INTEGER)  BEGIN
    insert into Commande(identifiantCommande, date_commande, date_recuperation, identifiantClient, identifiantSemaine) 
        values(unIdCommande, uneDateCommande, uneDateRecuperation, unIdClient, unIdSemaine);
END$$

CREATE DEFINER=`rmaissa`@`localhost` PROCEDURE `insertComporte` (IN `uneQuantite` FLOAT, IN `unIdProduit` INTEGER, IN `unIdCommande` INTEGER)  BEGIN
    INSERT INTO Comporte (quantite, identifiantProduit, identifiantCommande) VALUES (uneQuantite, unIdProduit, unIdCommande);
END$$

CREATE DEFINER=`rmaissa`@`localhost` PROCEDURE `insertProducteur` (IN `unNom` VARCHAR(50), IN `unPrenom` VARCHAR(50), IN `unMail` VARCHAR(50), IN `unTelephone` VARCHAR(50), IN `uneAdresse` VARCHAR(50), IN `unHoraire` VARCHAR(50), IN `unIdTypeAbonnement` INTEGER)  BEGIN
    insert into Producteur(nom, prenom, mail, telephone, adresse, horaire, identifiantTypeAbonnement) values(unNom, unPrenom, unMail, unTelephone, uneAdresse, unHoraire, unIdTypeAbonnement);
END$$

CREATE DEFINER=`rmaissa`@`localhost` PROCEDURE `insertProduit` (IN `unLibelle` VARCHAR(50), IN `unPrix` FLOAT, IN `uneQuantite` FLOAT, IN `uneDescription` VARCHAR(500), IN `unIdCategorie` INTEGER, IN `unIdProducteur` INTEGER, IN `unIdVariete` INTEGER, IN `unIdSemaine` INTEGER, IN `unIdUnite` INTEGER)  BEGIN
    insert into Produit(libelle, prix, quantite, description, identifiantCategorie, identifiantProducteur, identifiantVariete, identifiantSemaine, identifiantUnite) 
        values(unLibelle, unPrix, uneQuantite, uneDescription, unIdCategorie, unIdProducteur, unIdVariete, unIdSemaine, unIdUnite);
END$$

CREATE DEFINER=`rmaissa`@`localhost` PROCEDURE `insertRayon` (IN `unLibelle` VARCHAR(50))  BEGIN
    insert into Rayon(libelle) values(unLibelle);
END$$

CREATE DEFINER=`rmaissa`@`localhost` PROCEDURE `insertSemaine` (IN `uneDate` DATE)  BEGIN
    insert into Semaine(date) values(uneDate);
END$$

CREATE DEFINER=`rmaissa`@`localhost` PROCEDURE `insertTypeAbonnement` (IN `unLibelle` VARCHAR(50))  BEGIN
    insert into TypeAbonnement(libelle) values(unLibelle);
END$$

CREATE DEFINER=`rmaissa`@`localhost` PROCEDURE `insertUnite` (IN `unLibelle` VARCHAR(50))  BEGIN
    insert into Unite(libelle) values(unLibelle);
END$$

CREATE DEFINER=`rmaissa`@`localhost` PROCEDURE `insertVariete` (IN `unLibelle` VARCHAR(50), IN `unIdCategorie` INTEGER)  BEGIN
    insert into Variete(libelle, identifiantCategorie) values(unLibelle, unIdCategorie);
END$$

DELIMITER ;

-- --------------------------------------------------------

--
-- Structure de la table `Categorie`
--

CREATE TABLE `Categorie` (
  `identifiantCategorie` int(11) NOT NULL,
  `libelle` varchar(25) DEFAULT NULL,
  `dateEnregistrement` date DEFAULT current_timestamp(),
  `identifiantRayon` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `Categorie`
--

INSERT INTO `Categorie` (`identifiantCategorie`, `libelle`, `dateEnregistrement`, `identifiantRayon`) VALUES
(1, 'Pomme de Terre', NULL, 2),
(2, 'Salade', NULL, 2),
(3, 'Carotte', NULL, 2),
(4, 'Pomme', NULL, 1),
(6, 'poire', '2022-04-06', 1);

-- --------------------------------------------------------

--
-- Structure de la table `Client`
--

CREATE TABLE `Client` (
  `identifiantClient` int(11) NOT NULL,
  `nom` varchar(25) DEFAULT NULL,
  `prenom` varchar(25) DEFAULT NULL,
  `mail` varchar(60) DEFAULT NULL,
  `telephone` varchar(17) DEFAULT NULL,
  `adresse` varchar(150) DEFAULT NULL,
  `lienImage` varchar(50) DEFAULT NULL,
  `dateEnregistrement` date DEFAULT NULL,
  `actif` tinyint(1) DEFAULT 1
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `Client`
--

INSERT INTO `Client` (`identifiantClient`, `nom`, `prenom`, `mail`, `telephone`, `adresse`, `lienImage`, `dateEnregistrement`, `actif`) VALUES
(1, 'remi', 'maissa', 'maissa.rem08@gmail.com', '06 65 13 69 47', '175, rue pont sarrazin bas', NULL, NULL, 1),
(2, 'louis', 'vrai', 'louis.vrai@gmail.com', '06 65 89 85 12', 'zone La justice', NULL, NULL, 1);

-- --------------------------------------------------------

--
-- Structure de la table `Commande`
--

CREATE TABLE `Commande` (
  `identifiantCommande` int(11) NOT NULL,
  `date_commande` date DEFAULT NULL,
  `date_recuperation` date DEFAULT NULL,
  `identifiantClient` int(11) NOT NULL,
  `identifiantSemaine` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `Commande`
--

INSERT INTO `Commande` (`identifiantCommande`, `date_commande`, `date_recuperation`, `identifiantClient`, `identifiantSemaine`) VALUES
(1, '2021-09-12', NULL, 1, 1);

-- --------------------------------------------------------

--
-- Structure de la table `Comporte`
--

CREATE TABLE `Comporte` (
  `quantite` float DEFAULT NULL,
  `identifiantProduit` int(11) NOT NULL,
  `identifiantCommande` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `Comporte`
--

INSERT INTO `Comporte` (`quantite`, `identifiantProduit`, `identifiantCommande`) VALUES
(2, 1, 1),
(3, 2, 1);

-- --------------------------------------------------------

--
-- Structure de la table `Producteur`
--

CREATE TABLE `Producteur` (
  `identifiantProducteur` int(11) NOT NULL,
  `nom` varchar(25) DEFAULT NULL,
  `prenom` varchar(25) DEFAULT NULL,
  `mail` varchar(60) DEFAULT NULL,
  `telephone` varchar(17) DEFAULT NULL,
  `adresse` varchar(60) DEFAULT NULL,
  `horaire` time DEFAULT NULL,
  `dateEnregistrement` date DEFAULT NULL,
  `actif` tinyint(1) DEFAULT 1,
  `identifiantTypeAbonnement` int(11) NOT NULL DEFAULT 2,
  `consultationRegistre` tinyint(1) DEFAULT 0,
  `contactTelephonique` tinyint(1) DEFAULT 0,
  `VisiteExploitation` tinyint(1) DEFAULT 0,
  `consultationAnnuaire` tinyint(1) NOT NULL DEFAULT 0,
  `raisonInvalidation` varchar(1000) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `Producteur`
--

INSERT INTO `Producteur` (`identifiantProducteur`, `nom`, `prenom`, `mail`, `telephone`, `adresse`, `horaire`, `dateEnregistrement`, `actif`, `identifiantTypeAbonnement`, `consultationRegistre`, `contactTelephonique`, `VisiteExploitation`, `consultationAnnuaire`, `raisonInvalidation`) VALUES
(1, 'andre', 'michel', 'paysan05@gmail.com', '07 05 26 35 58', '12, impasse champ fleurie', NULL, NULL, 1, 1, 0, 0, 0, 0, ''),
(2, 'bernard', 'bruno', 'bernard.bruno05@gmail.com', '12 23 34 45 56', '46, impasse champ fleurie', NULL, '2022-03-02', 1, 1, 1, 1, 1, 1, 'test'),
(3, 'bernard', 'brigite', 'bernard.brigite@gmail.com', '06 98 87 65 54', '46, impasse champ fleurie', NULL, '2022-03-02', 0, 1, 0, 0, 0, 0, ''),
(4, 'maissa', 'remi', 'test@gmail.com', '05 30 25 47 56', '75, rue de la ravierre', NULL, '2022-03-23', 1, 3, 0, 0, 0, 0, 'coucou ceci est un test');

-- --------------------------------------------------------

--
-- Structure de la table `Produit`
--

CREATE TABLE `Produit` (
  `identifiantProduit` int(11) NOT NULL,
  `libelle` varchar(25) DEFAULT NULL,
  `prix` int(11) DEFAULT NULL,
  `quantite` int(11) DEFAULT NULL,
  `image` varchar(60) DEFAULT NULL,
  `description` varchar(500) DEFAULT NULL,
  `dateEnregistrement` date DEFAULT current_timestamp(),
  `actif` tinyint(1) DEFAULT 1,
  `identifiantCategorie` int(11) NOT NULL,
  `identifiantProducteur` int(11) NOT NULL,
  `identifiantVariete` int(11) NOT NULL,
  `identifiantSemaine` int(11) NOT NULL,
  `identifiantUnite` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `Produit`
--

INSERT INTO `Produit` (`identifiantProduit`, `libelle`, `prix`, `quantite`, `image`, `description`, `dateEnregistrement`, `actif`, `identifiantCategorie`, `identifiantProducteur`, `identifiantVariete`, `identifiantSemaine`, `identifiantUnite`) VALUES
(1, 'Patate maison', 16, 53, NULL, 'De bonne patate pour vos raclettes en famille', '2022-03-29', 1, 1, 1, 5, 2, 2),
(2, 'Carotte', 6, 35, NULL, 'De bonne carotte 100% naturel cultivé avec passion', '2022-03-23', 1, 3, 1, 9, 1, 1);

-- --------------------------------------------------------

--
-- Structure de la table `Rayon`
--

CREATE TABLE `Rayon` (
  `identifiantRayon` int(11) NOT NULL,
  `libelle` varchar(25) DEFAULT NULL,
  `lienImage` varchar(500) DEFAULT NULL,
  `dateEnregistrement` date DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `Rayon`
--

INSERT INTO `Rayon` (`identifiantRayon`, `libelle`, `lienImage`, `dateEnregistrement`) VALUES
(1, 'Fruit', '/home/rmaissa/Images/Qt/newWorld_backOffice/fruit.jpg', NULL),
(2, 'Legume', '/home/rmaissa/Images/Qt/newWorld_backOffice/legume.jpeg', NULL),
(3, 'Viande', '/home/rmaissa/Images/Qt/newWorld_backOffice/viande.jpeg', NULL),
(4, 'Volaille', '/home/rmaissa/Images/Qt/newWorld_backOffice/volaille.jpeg', NULL),
(5, 'Laitier', '/home/rmaissa/Images/Qt/newWorld_backOffice/laitier.jpeg', NULL),
(6, 'poisson', '/home/rmaissa/Images/Qt/newWorld_backOffice/poisson.jpg', NULL);

-- --------------------------------------------------------

--
-- Structure de la table `Semaine`
--

CREATE TABLE `Semaine` (
  `identifiantSemaine` int(11) NOT NULL,
  `date` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `Semaine`
--

INSERT INTO `Semaine` (`identifiantSemaine`, `date`) VALUES
(1, '2021-09-10'),
(2, '2021-09-17');

-- --------------------------------------------------------

--
-- Structure de la table `Ticket`
--

CREATE TABLE `Ticket` (
  `numeroTicket` int(11) NOT NULL,
  `clefTicket` varchar(75) DEFAULT NULL,
  `identifiantSemaine` int(11) NOT NULL,
  `identifiantClient` int(11) NOT NULL,
  `identifiantProducteur` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Structure de la table `TypeAbonnement`
--

CREATE TABLE `TypeAbonnement` (
  `identifiantTypeAbonnement` int(11) NOT NULL,
  `libelle` varchar(25) DEFAULT NULL,
  `imageImage` varchar(50) DEFAULT NULL,
  `dateEnregistrement` date DEFAULT NULL,
  `actif` tinyint(1) DEFAULT 1
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `TypeAbonnement`
--

INSERT INTO `TypeAbonnement` (`identifiantTypeAbonnement`, `libelle`, `imageImage`, `dateEnregistrement`, `actif`) VALUES
(1, 'basique', NULL, '2022-01-02', 1),
(2, 'a verifier', NULL, '2022-03-02', 1),
(3, 'invalide', NULL, '2022-03-23', 1);

-- --------------------------------------------------------

--
-- Structure de la table `TypeRoleUtilisateur`
--

CREATE TABLE `TypeRoleUtilisateur` (
  `id` int(11) NOT NULL,
  `libelle` varchar(25) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `TypeRoleUtilisateur`
--

INSERT INTO `TypeRoleUtilisateur` (`id`, `libelle`) VALUES
(1, 'moderateur'),
(2, 'administrateur'),
(3, 'superAdministrateur');

-- --------------------------------------------------------

--
-- Structure de la table `Unite`
--

CREATE TABLE `Unite` (
  `identifiantUnite` int(11) NOT NULL,
  `libelle` varchar(150) DEFAULT NULL,
  `lienImage` varchar(50) DEFAULT NULL,
  `dateEnregistrement` date DEFAULT NULL,
  `actif` tinyint(1) DEFAULT 1
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `Unite`
--

INSERT INTO `Unite` (`identifiantUnite`, `libelle`, `lienImage`, `dateEnregistrement`, `actif`) VALUES
(1, 'Cagette', NULL, NULL, 1),
(2, 'Sac', NULL, NULL, 1),
(3, 'Piece', NULL, NULL, 1);

-- --------------------------------------------------------

--
-- Structure de la table `Utilisateur`
--

CREATE TABLE `Utilisateur` (
  `numUtilisateur` int(11) NOT NULL,
  `login` varchar(25) NOT NULL,
  `nom` varchar(50) DEFAULT NULL,
  `prenom` varchar(50) DEFAULT NULL,
  `adresse` varchar(50) DEFAULT NULL,
  `ville` varchar(50) DEFAULT NULL,
  `codePostal` int(11) DEFAULT NULL,
  `telephone` varchar(17) DEFAULT NULL,
  `motDePasse` varchar(41) DEFAULT NULL,
  `mail` varchar(100) DEFAULT NULL,
  `dateEnregistrement` date DEFAULT NULL,
  `actif` tinyint(1) DEFAULT 1,
  `idRole` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `Utilisateur`
--

INSERT INTO `Utilisateur` (`numUtilisateur`, `login`, `nom`, `prenom`, `adresse`, `ville`, `codePostal`, `telephone`, `motDePasse`, `mail`, `dateEnregistrement`, `actif`, `idRole`) VALUES
(1, 'admin', 'SuperUtilisateur', NULL, NULL, NULL, NULL, NULL, '*2D1058E7C081583392B50D63C68CB22293A789E3', NULL, '2022-03-02', 1, 3),
(2, 'rmaissa', 'maissa', 'remi', '175, pont sarrazin', 'la rochette', 5000, '0665136947', '*C2B1F62C921648AFE85E95C75097BEF2356B4F6A', 'admin@ploum.fr', '2021-12-10', 1, 3),
(3, 'test', 'maissa', 'remi', 'coucou', 'sisteron', 5001, '12345678', '*6B4F89A54E2D27ECD7E8DA05B4AB8FD9D1D8B119', 'test@ploum.fr', '2022-03-02', 1, 2);

-- --------------------------------------------------------

--
-- Structure de la table `Variete`
--

CREATE TABLE `Variete` (
  `identifiantVariete` int(11) NOT NULL,
  `libelle` varchar(25) DEFAULT NULL,
  `lienImage` varchar(50) DEFAULT NULL,
  `dateEnregistrement` date DEFAULT NULL,
  `identifiantCategorie` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `Variete`
--

INSERT INTO `Variete` (`identifiantVariete`, `libelle`, `lienImage`, `dateEnregistrement`, `identifiantCategorie`) VALUES
(1, 'Mache', NULL, NULL, 2),
(2, 'Sucrine', NULL, NULL, 2),
(3, 'Roquette', NULL, NULL, 2),
(4, 'Amandine', NULL, NULL, 1),
(5, 'Balmoral', NULL, NULL, 1),
(6, 'Monalisa', NULL, NULL, 1),
(7, 'Ansterdam', NULL, NULL, 3),
(8, 'Chantenay', NULL, NULL, 3),
(9, 'Flyaway', NULL, NULL, 3);

-- --------------------------------------------------------

--
-- Structure de la table `Verification`
--

CREATE TABLE `Verification` (
  `verifie` tinyint(1) DEFAULT NULL,
  `raison` varchar(100) DEFAULT NULL,
  `identifiantProducteur` int(11) NOT NULL,
  `login` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `Categorie`
--
ALTER TABLE `Categorie`
  ADD PRIMARY KEY (`identifiantCategorie`),
  ADD KEY `identifiantRayon` (`identifiantRayon`);

--
-- Index pour la table `Client`
--
ALTER TABLE `Client`
  ADD PRIMARY KEY (`identifiantClient`);

--
-- Index pour la table `Commande`
--
ALTER TABLE `Commande`
  ADD PRIMARY KEY (`identifiantCommande`),
  ADD KEY `identifiantClient` (`identifiantClient`),
  ADD KEY `identifiantSemaine` (`identifiantSemaine`);

--
-- Index pour la table `Comporte`
--
ALTER TABLE `Comporte`
  ADD PRIMARY KEY (`identifiantProduit`,`identifiantCommande`),
  ADD KEY `identifiantCommande` (`identifiantCommande`);

--
-- Index pour la table `Producteur`
--
ALTER TABLE `Producteur`
  ADD PRIMARY KEY (`identifiantProducteur`),
  ADD KEY `identifiantTypeAbonnement` (`identifiantTypeAbonnement`);

--
-- Index pour la table `Produit`
--
ALTER TABLE `Produit`
  ADD PRIMARY KEY (`identifiantProduit`),
  ADD KEY `identifiantCategorie` (`identifiantCategorie`),
  ADD KEY `identifiantProducteur` (`identifiantProducteur`),
  ADD KEY `identifiantVariete` (`identifiantVariete`),
  ADD KEY `identifiantSemaine` (`identifiantSemaine`),
  ADD KEY `identifiantUnite` (`identifiantUnite`);

--
-- Index pour la table `Rayon`
--
ALTER TABLE `Rayon`
  ADD PRIMARY KEY (`identifiantRayon`);

--
-- Index pour la table `Semaine`
--
ALTER TABLE `Semaine`
  ADD PRIMARY KEY (`identifiantSemaine`);

--
-- Index pour la table `Ticket`
--
ALTER TABLE `Ticket`
  ADD PRIMARY KEY (`numeroTicket`),
  ADD KEY `identifiantSemaine` (`identifiantSemaine`),
  ADD KEY `identifiantClient` (`identifiantClient`),
  ADD KEY `identifiantProducteur` (`identifiantProducteur`);

--
-- Index pour la table `TypeAbonnement`
--
ALTER TABLE `TypeAbonnement`
  ADD PRIMARY KEY (`identifiantTypeAbonnement`);

--
-- Index pour la table `TypeRoleUtilisateur`
--
ALTER TABLE `TypeRoleUtilisateur`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `Unite`
--
ALTER TABLE `Unite`
  ADD PRIMARY KEY (`identifiantUnite`);

--
-- Index pour la table `Utilisateur`
--
ALTER TABLE `Utilisateur`
  ADD PRIMARY KEY (`numUtilisateur`),
  ADD KEY `id` (`idRole`);

--
-- Index pour la table `Variete`
--
ALTER TABLE `Variete`
  ADD PRIMARY KEY (`identifiantVariete`),
  ADD KEY `identifiantCategorie` (`identifiantCategorie`);

--
-- Index pour la table `Verification`
--
ALTER TABLE `Verification`
  ADD PRIMARY KEY (`identifiantProducteur`),
  ADD KEY `login` (`login`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `Categorie`
--
ALTER TABLE `Categorie`
  MODIFY `identifiantCategorie` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT pour la table `Client`
--
ALTER TABLE `Client`
  MODIFY `identifiantClient` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT pour la table `Commande`
--
ALTER TABLE `Commande`
  MODIFY `identifiantCommande` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT pour la table `Producteur`
--
ALTER TABLE `Producteur`
  MODIFY `identifiantProducteur` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT pour la table `Produit`
--
ALTER TABLE `Produit`
  MODIFY `identifiantProduit` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT pour la table `Rayon`
--
ALTER TABLE `Rayon`
  MODIFY `identifiantRayon` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- AUTO_INCREMENT pour la table `Semaine`
--
ALTER TABLE `Semaine`
  MODIFY `identifiantSemaine` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT pour la table `Ticket`
--
ALTER TABLE `Ticket`
  MODIFY `numeroTicket` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `TypeAbonnement`
--
ALTER TABLE `TypeAbonnement`
  MODIFY `identifiantTypeAbonnement` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT pour la table `TypeRoleUtilisateur`
--
ALTER TABLE `TypeRoleUtilisateur`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT pour la table `Unite`
--
ALTER TABLE `Unite`
  MODIFY `identifiantUnite` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT pour la table `Utilisateur`
--
ALTER TABLE `Utilisateur`
  MODIFY `numUtilisateur` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT pour la table `Variete`
--
ALTER TABLE `Variete`
  MODIFY `identifiantVariete` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;

--
-- Contraintes pour les tables déchargées
--

--
-- Contraintes pour la table `Categorie`
--
ALTER TABLE `Categorie`
  ADD CONSTRAINT `Categorie_ibfk_1` FOREIGN KEY (`identifiantRayon`) REFERENCES `Rayon` (`identifiantRayon`);

--
-- Contraintes pour la table `Commande`
--
ALTER TABLE `Commande`
  ADD CONSTRAINT `Commande_ibfk_1` FOREIGN KEY (`identifiantClient`) REFERENCES `Client` (`identifiantClient`),
  ADD CONSTRAINT `Commande_ibfk_2` FOREIGN KEY (`identifiantSemaine`) REFERENCES `Semaine` (`identifiantSemaine`);

--
-- Contraintes pour la table `Comporte`
--
ALTER TABLE `Comporte`
  ADD CONSTRAINT `Comporte_ibfk_1` FOREIGN KEY (`identifiantProduit`) REFERENCES `Produit` (`identifiantProduit`),
  ADD CONSTRAINT `Comporte_ibfk_2` FOREIGN KEY (`identifiantCommande`) REFERENCES `Commande` (`identifiantCommande`);

--
-- Contraintes pour la table `Producteur`
--
ALTER TABLE `Producteur`
  ADD CONSTRAINT `Producteur_ibfk_1` FOREIGN KEY (`identifiantTypeAbonnement`) REFERENCES `TypeAbonnement` (`identifiantTypeAbonnement`);

--
-- Contraintes pour la table `Produit`
--
ALTER TABLE `Produit`
  ADD CONSTRAINT `Produit_ibfk_1` FOREIGN KEY (`identifiantCategorie`) REFERENCES `Categorie` (`identifiantCategorie`),
  ADD CONSTRAINT `Produit_ibfk_2` FOREIGN KEY (`identifiantProducteur`) REFERENCES `Producteur` (`identifiantProducteur`),
  ADD CONSTRAINT `Produit_ibfk_3` FOREIGN KEY (`identifiantVariete`) REFERENCES `Variete` (`identifiantVariete`),
  ADD CONSTRAINT `Produit_ibfk_4` FOREIGN KEY (`identifiantSemaine`) REFERENCES `Semaine` (`identifiantSemaine`),
  ADD CONSTRAINT `Produit_ibfk_5` FOREIGN KEY (`identifiantUnite`) REFERENCES `Unite` (`identifiantUnite`);

--
-- Contraintes pour la table `Ticket`
--
ALTER TABLE `Ticket`
  ADD CONSTRAINT `Ticket_ibfk_1` FOREIGN KEY (`identifiantSemaine`) REFERENCES `Semaine` (`identifiantSemaine`),
  ADD CONSTRAINT `Ticket_ibfk_2` FOREIGN KEY (`identifiantClient`) REFERENCES `Client` (`identifiantClient`),
  ADD CONSTRAINT `Ticket_ibfk_3` FOREIGN KEY (`identifiantProducteur`) REFERENCES `Producteur` (`identifiantProducteur`);

--
-- Contraintes pour la table `Utilisateur`
--
ALTER TABLE `Utilisateur`
  ADD CONSTRAINT `Utilisateur_ibfk_1` FOREIGN KEY (`idRole`) REFERENCES `TypeRoleUtilisateur` (`id`);

--
-- Contraintes pour la table `Variete`
--
ALTER TABLE `Variete`
  ADD CONSTRAINT `Variete_ibfk_1` FOREIGN KEY (`identifiantCategorie`) REFERENCES `Categorie` (`identifiantCategorie`);

--
-- Contraintes pour la table `Verification`
--
ALTER TABLE `Verification`
  ADD CONSTRAINT `Verification_ibfk_1` FOREIGN KEY (`identifiantProducteur`) REFERENCES `Producteur` (`identifiantProducteur`),
  ADD CONSTRAINT `Verification_ibfk_2` FOREIGN KEY (`login`) REFERENCES `Utilisateur` (`numUtilisateur`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
