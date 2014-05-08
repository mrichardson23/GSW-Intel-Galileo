import json
import urllib2

httpResponse = urllib2.urlopen('http://nextmakemagazine.appspot.com/json')
jsonString = httpResponse.read()

jsonData = json.loads(jsonString)

print "Volume", jsonData['volumeNumber'], "will be released in", jsonData['totalHours'], "hours."