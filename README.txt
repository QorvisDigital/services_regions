Adds a service resource for regions.
Enable services 3.x and it's core rest server.
1 - Make a rest server called rest, and enable the region resource for it.
2 - POST TO example.com/rest/region/retrieve.json with data:
      path = path of the page you want to render
      regions (optional) = array of regions you want to return
      
      ex: example.com/rest/region/fetch.json
      or: example.com/rest/region/fetch.json
      
406|3|4? PROTIP:
  admin/structure/services/list/APINAME/server
  enable aaplication/x-www-form-urlencoded

Example post using jQuery:
jQuery.ajax({
  type: 'POST',
  url: location.protocol + '//' + location.host + Drupal.settings.basePath + 'rest/region/fetch.json',
  data: {path:'<front>'},
  success: function(d,m){console.log(d);console.log(m)},
  dataType: 'json'
});

