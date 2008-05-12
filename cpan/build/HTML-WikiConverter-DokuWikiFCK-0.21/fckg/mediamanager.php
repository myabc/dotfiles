<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
 "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<?php
/**
 * DokuWiki Default Template
 *
 * This is the template for the media manager popup
 *
 * You should leave the doctype at the very top - It should
 * always be the very first line of a document.
 *
 * @link   http://wiki.splitbrain.org/wiki:tpl:templates
 * @author Andreas Gohr <andi@splitbrain.org>
 */
?>
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php echo $conf['lang']?>" lang="<?php echo $conf['lang']?>" dir="ltr">
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <title>
    <?php echo hsc($lang['mediaselect'])?>
    [<?php echo strip_tags($conf['title'])?>]
  </title>
  <?php tpl_metaheaders()?>
  <link rel="shortcut icon" href="<?php echo DOKU_TPL?>images/favicon.ico" />

  <script type="text/javascript" charset="utf-8" ><!--//--><![CDATA[//><!--

        var UsingFCKImageManager = false;  
        if(!opener || (opener && !opener.insertTags)) {
            opener = new Object();
            UsingFCKImageManager = true;
            opener.focus = function() {};
            opener.insertTags = function(edid,tagOpen, tagClose, sampleText) {
                    alert("Use GUI Image Manager to Insert Images");
            };
	
            window.onerror = function(msg,url, line) {
               return true;
            }
            
            function setupFCK(dom) {
               setFCK_bgfg('media__manager');
               setFCK_bgfg('media__left');
               setFCK_bgfg('media__opts');
               setFCK_bgfg('media__right');
               setFCK_bgfg('media__content');
               setFCK_bgfg('info_list_2');
               setFCK_bgfg('info_list_1');
               setFCK_bgfgDark('mselect_title');
               setFCK_bgfgDark('media__ns');
               setFCK_bgfg('img_on_file');
               setFCK_bgfg('upload__name');
               setFCK_bgfg('upload__file');
               setFCK_bgfg('all');

            }
            function setFCK_bgfg(id) {
               var dom =document.getElementById(id);               
               dom.style.backgroundColor = "#F1F1E3";             
               dom.style.color = "#737357";
               dom.style.fontFamily = "arial,helvetica";
            }

            function setFCK_bgfgDark(id) {
               var dom =document.getElementById(id);               
               dom.style.backgroundColor = "#E3E3C7";             
               dom.style.color = "#737357";
               dom.style.fontFamily = "arial,helvetica";              
            }

        }
        else {
            var setupFCK = function(){ };            
        }
 

      function G_onsubmithandler() {
          var filename = document.getElementById('upload__name').value;
           if(!filename){
	    alert("Please enter a file for uploading");
	    return false;
	   }
           elems = filename.split(/\./);
           ext = elems.pop();
           if(!ext.match(/(jpeg|jpg|png|gif|bmp)/)) {
              alert('filetype not supported: ' + ext);
              return false;
           }            
	    setupFCK(document.getElementById('media__manager'));   
            return true;	  
      }

      function Gmedia_onLoadHandler() {
             document.forms[0].onsubmit = G_onsubmithandler;
             var m_hide = document.getElementById('media__hide');
             if(m_hide)  m_hide.click();    

             var labels = document.getElementsByTagName('label');
             for(var i=0; i< labels.length; i++) {
                if(labels[i]['htmlFor'].match(/media__hide/i)) {
                      labels[i].innerHTML = "Hide Thumbnails";
                      break;  
                }
            }           
           setupFCK(document.getElementById('media__manager'));   
      }

  //--><!]]></script>

</head>


<body id= "all" onload = "Gmedia_onLoadHandler();" onreload=setupFCK();">
<div id="media__manager" class="dokuwiki">
    <div id="media__left">
        <?php html_msgarea()?>
        <h1><?php echo hsc($lang['mediaselect'])?></h1>

        <?php /* keep the id! additional elements are inserted via JS here */?>
        <div id="media__opts"></div>

        <?php tpl_mediaTree() ?>
    </div>

    <div id="media__right">
        <?php tpl_mediaContent() ?>
    </div>
</div>
</body>
</html>
