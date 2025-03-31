<?php
$url = strtoupper($_GET['url']);
if ($url == "CADASTROUSUARIO") {
    require_once "view/cadastro.php";
}
?>