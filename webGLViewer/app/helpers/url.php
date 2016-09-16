<?php

/*
 *---------------------------------------------------------------
 * URL UTILS
 *---------------------------------------------------------------
 *
 * All related url functions
 */


// Parse the path
function parsePath($firephp) {
  $path = array();
  if (isset($_SERVER['REQUEST_URI'])) {
    $request_path = explode('?', $_SERVER['REQUEST_URI']);
    $firephp->fb("request_path: ");
    $firephp->fb($request_path[0]);

    $path['base'] = rtrim(dirname($_SERVER['SCRIPT_NAME']), '\/');
    

    $firephp->fb("urldecode(str): ");
    $firephp->fb(urldecode($request_path[0]), strlen($path['base']));

    $path['call_utf8'] = substr(urldecode($request_path[0]), strlen($path['base']) + 1);
    $path['call'] = utf8_decode($path['call_utf8']);
    if ($path['call'] == basename($_SERVER['PHP_SELF'])) {
      $path['call'] = '';
    }
    $path['call_parts'] = explode('/', $path['call']);

    $path['query_utf8'] = urldecode($request_path[1]);
    $path['query'] = utf8_decode(urldecode($request_path[1]));
    $firephp->fb("path -->");
    $firephp->fb($path);
    $firephp->fb("");

    $vars = explode('&', $path['query']);
    foreach ($vars as $var) {
      $t = explode('=', $var);
      $path['query_vars'][$t[0]] = $t[1];
    }
  }
return $path;
}

?>