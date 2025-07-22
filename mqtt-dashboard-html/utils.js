function logMessage(msg) {
  const log = document.getElementById('log')
  const entry = document.createElement('div')
  entry.innerText = JSON.stringify(msg)
  log.prepend(entry)
}
