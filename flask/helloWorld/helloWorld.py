from flask import Flask
app = Flask(__name__)

@app.route('/')
def hello_world():
   return 'Hello World! (copied from: https://www.fullstackpython.com/flask.html)'

if __name__ == '__main__':
   app.run(host='0.0.0.0')
