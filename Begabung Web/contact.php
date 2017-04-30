<!DOCTYPE HTML>
<html>

<head>
  <title>CSS3_one</title>
  <meta name="description" content="website description" />
  <meta name="keywords" content="website keywords, website keywords" />
  <meta http-equiv="content-type" content="text/html; charset=UTF-8" />
  <link rel="stylesheet" type="text/css" href="css/style.css" />
  <!-- modernizr enables HTML5 elements and feature detects -->
  <script type="text/javascript" src="js/modernizr-1.5.min.js"></script>
</head>

<body>
  <div id="main">
    <header>
      <div id="logo">
        <div id="logo_text">
          <!-- class="logo_colour", allows you to change the colour of the text -->
          <h1><a href="index.html">El éxito<span class="logo_colour"> en una pulsera</span></a></h1>
          <h2>BegaBung</h2>
        </div>
        <form method="post" action="#" id="search">
          <input class="search" type="text" name="search_field" value="search....." onclick="javascript: document.forms['search'].search_field.value=''" />
          <input name="search" type="image" style="float: right;border: 0; margin: 20px 0 0 0;" src="images/search.png" alt="search" title="search" />
        </form>
      </div>
      <nav>
        <ul class="sf-menu" id="nav">
          <li><a href="index.html">Inicio</a></li>
          <li><a href="menu1.html">Jugadores</a></li>
          <li><a href="menu2.html">BB</a></li>
          <li><a href="menu3.html">+Info</a></li>
          <li><a href="#">Filtro</a>
            <ul>
               <li><a href="#">Portero</a></li>
              <li><a href="#">Defensa</a>
                <ul>
                  <li><a href="#">Contencion</a></li>
                  <li><a href="#">Lateral</a></li>
                  <li><a href="#">Centro</a></li>
                </ul>
              </li>
              <li><a href="#">Carrileros</a></li>
              <li><a href="#">Medios</a></li>
              <li><a href="#">Delanteros</a></li>
            </ul>
          </li>
          <li class="current"><a href="contact.php">Contacto</a></li>
        </ul>
      </nav>
    </header>
    <div id="site_content">
      <div id="sidebar_container">
        <div class="sidebar">
          <h3>Recomendaciones</h3>
          <div class="sidebar_item"> </div>
          <div class="sidebar_base"></div>
        </div>
      </div>
      <div class="content">
        <h1>Contacto</h1>
        <div class="content_item">
          <p>Say hello, using this contact form.</p>
          <form id="contact" action="contact.php" method="post">
            <div class="form_settings">
              <p><span>Name</span><input class="contact" type="text" name="your_name" value="<?php echo $yourname; ?>" /></p>
              <p><span>Email Address</span><input class="contact" type="text" name="your_email" value="<?php echo $youremail; ?>" /></p>
              <p><span>Message</span><textarea class="contact textarea" rows="5" cols="50" name="your_message"><?php echo $yourmessage; ?></textarea></p>
              <p style="line-height: 1.7em;">To help prevent spam, please enter the answer to this question:</p>
              <p><span><?php echo $number_1; ?> + <?php echo $number_2; ?> = ?</span><input type="text" name="user_answer" /><input type="hidden" name="answer" value="<?php echo $answer; ?>" /></p>
              <p style="padding-top: 15px"><span>&nbsp;</span><input class="submit" type="submit" name="contact_submitted" value="send" /></p>
            </div>
          </form>
        </div>
      </div>
    </div>
    <footer>
      <p><a href="index.html">Inicio</a> | <a href="menu1.html">Menu1</a> | <a href="menu2.html">menu2</a> | <a href="menu3.html">menu3</a> | <a href="contact.php">Contacto</a></p>
       <p>Nuestra privacidad <a href="http://www.css3templates.co.uk">Codigo Facilito</a></p>
    </footer>
  </div>
  
  <script type="text/javascript" src="js/jquery.js"></script>
  <script type="text/javascript" src="js/jquery.easing-sooper.js"></script>
  <script type="text/javascript" src="js/jquery.sooperfish.js"></script>
  <script type="text/javascript">
    $(document).ready(function() {
      $('ul.sf-menu').sooperfish();
    });
  </script>
</body>
</html>