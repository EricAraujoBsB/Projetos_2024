<!-- MENU SUPERIOR -->
<nav class="navbar navbar-expand-sm navbar-dark estilo-background-nav">
  <!-- Brand -->
  <a class="navbar-brand" href="home" id="tituloNav">ROTA<br>Airlines</a>

  <!-- Links -->
  <ul class="navbar-nav">
    <!-- Dropdown -->
    <li class="nav-item dropdown">
      <a class="nav-link dropdown-toggle custom-nav-text nav-text-Custom" href="#" id="navbardrop"
        data-toggle="dropdown">
        Minhas Viagens
      </a>
      <div class="dropdown-menu">
        <a class="dropdown-item" href="#" data-toggle="modal" data-target="#myModal">Checkin</a>
      </div>
    </li>
  </ul>
  <ul class="navbar-nav ml-auto">
      <li class="nav-item dropdown">
        <a class="nav-link dropdown-toggle custom-nav-text nav-text-Custom" href="#" id="navbardrop"
          data-toggle="dropdown">
          Bem-vindo,
        </a>
        <div class="dropdown-menu">
          <a class="dropdown-item" href="dashboard">Meu Dashboard</a>
          <a class="dropdown-item" href="DESLOGAR">Sair</a>
        </div>
      </li>
      <li class="nav-item">
        <a class="nav-link" href="login"><span class="glyphicon glyphicon-log-in"></span> Fazer Login</a>
      </li>
  </ul>

</nav>

<!-- CHECKIN -->
<div class="modal fade" id="myModal" role="dialog">
  <div class="modal-dialog">

    <!-- Modal content-->
    <div class="modal-content">
      <div class="modal-header">
        <h4>Pronto para iniciar seu check-in?</h4>
        <button type="button" class="close" data-dismiss="modal">&times;</button>
      </div>
      <div class="modal-body">
      <form type="submit" method="post" action="VALIDACHECKIN">
          <div class="form-group">
            <label for="email">Buscar Reserva por:</label>
            <input type="text" value="Codigo da Reserva" class="form-control" readonly>
          </div>
          <div class="form-group">
            <label for="pwd">Código da Reserva</label>
            <input type="text" class="form-control" id="pwd" placeholder="Digite o Código da Reserva" name="cdReserva">
          </div>
          <button type="submit" class="btn btn-primary btn-custom" style="width: 100%;">Iniciar Chek-in</button>
        </form>
      </div>
      <div class="modal-footer">
        <button type="button" class="btn btn-default" data-dismiss="modal">Cancelar</button>
      </div>
    </div>

  </div>
</div>