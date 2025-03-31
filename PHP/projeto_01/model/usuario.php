<?php
class Usuario{
    //atributos
    private $nomeUsuario;
    private $email;
    private $dtaNasc;
    private $sexo;
    Private $paisNasc;
    private $numTel;
    private $cpf;
    private $senha;
    private $idUsuario;

    //GETs e SETs
    public function get_nomeUsuario(){
        return $this->nomeUsuario;
    }
    public function set_nomeUsuario($nomeUsuario){
        $this->nomeUsuario = $nomeUsuario;
    }
    public function getEmail(){
        return $this->email;
    }
    public function setEmail($email){ 
        $this->email = $email;
    }
    public function getDtaNasc(){
        return $this->dtaNasc;
    }
    public function setDtaNasc($dtaNasc){
        $this->dtaNasc = $dtaNasc;
    }
    public function getSexo(){
        return $this->sexo;
    }
    public function setSexo($sexo){
        $this->sexo = $sexo;
    }
    public function getPaisNasc(){
        return $this->paisNasc;
    }
    public function setPaisNasc($paisNasc){
        $this->paisNasc = $paisNasc;
    }
    public function getNumTel(){
        return $this->numTel;
    }
    public function setNumTel($numTel){
        $this->numTel = $numTel;
    }
}
?>