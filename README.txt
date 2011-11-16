Adds a service resource for regions.
Enable services 3.x and it's core rest server.
1 - Make a rest server called rest, and enable the region resource for it.
2 - Visit example.com/rest/region/retrieve.json with queries:
      path = path of the page you want to render
      regions (optional) = array of regions you want to return
      
      ex: example.com/rest/region/retrieve.json/?path=node&regions[]=content
      or: example.com/rest/region/retrieve.json/?path=node
