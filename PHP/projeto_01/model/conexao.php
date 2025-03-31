<?php
class Conexao
{
    public static function conectar()
    {
        $servername = "localhost";
        $username = "root";
        $password = "";

        try {

            $conn = new PDO("mysql:host=$servername; dbname = rotaxirlines", $username, $password);
            $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
            echo "conexao realizada com sucesso!";
            return $conn;
        } catch (PDOException $e) {
            echo ("conexao falhou!" . $e->getMessage());
            return null;
        }
    }
}



?>