<?hh // strict
use XHPRoot;
class :layouts:front extends :layouts:master {
  attribute
    string title @required;
  public function compose() : XHPRoot {
    $this->setTitle('Decouple | Home');
    $this->addStyle('semantic', '//cdnjs.cloudflare.com/ajax/libs/semantic-ui/0.16.1/css/semantic.min.css');
    $this->addStyle('main', '/assets/main.css');
    $this->addScript('semantic', '//cdnjs.cloudflare.com/ajax/libs/semantic-ui/0.16.1/javascript/semantic.min.js');
    $this->prependChild(<layouts:header schema={$this->getAttribute('schema')} title={$this->getAttribute('title')}/>);
    return parent::compose();
  }
}
