from centrifugate import Centrifugator 

class TestCentrifugator(Centrifugator):
	
	def __init__(self, params):
		"""constructor"""

	def startCentrifugate(self, communications, intensity):
		"""
			must send instructions to the machine to start centrifugating with an intensity of "intensity" Hz
			the command must be sended throught the communications object,
			communications object has the next api:
				*) nbytessend sendString(string) -- send the string to the machine, return the bytes sended;
				*) string receiveString() -- receive and returns a string from the machine (stops when \n is received), can block;
				*) string readUntil(endCharacter) -- returns a string received from the machine, stops when the endCharacter arrives;
				*) void synchronize() -- synchronize with the machine;
		"""
		communications.sendString("START CENTRIFUGATE" + str(intensity))

	def stopCentrifugate(self, communications):
		"""
			must send instructions to the machine to stop centrifugating,
			the command must be sended throught the communications object,
			communications object has the next api:
				*) nbytessend sendString(string) -- send the string to the machine, return the bytes sended;
				*) string receiveString() -- receive and returns a string from the machine (stops when \n is received), can block;
				*) string readUntil(endCharacter) -- returns a string received from the machine, stops when the endCharacter arrives;
				*) void synchronize() -- synchronize with the machine;
		"""
		communications.sendString("STOP CENTRIFUGATE")