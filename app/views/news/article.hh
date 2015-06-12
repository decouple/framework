<?hh // decl
class :news:article extends :x:element {
  use XHPAsync;
  attribute
    KeyedTraversable<string,mixed> article @required;

  public async function asyncRender(): Awaitable<XHPRoot> {
    $article = $this->getAttribute('article');
    return
      <div class="item">
        <div class="ui large rounded image">
          <img src={$article['image']}/>
          <a class="like ui corner label">
            <i class="like icon"></i>
          </a>
        </div>
        <h4 class="header"></h4>
        <div class="content">
          <div class="name">{$article['title']}</div>
          <p class="description">{$article['content']}</p>
          <div class="extra">{$article['date']}</div>
        </div>
      </div>
    ;
  }
}
