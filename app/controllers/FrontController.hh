<?hh // strict
use Decouple\Ui\Ui;
use Decouple\Common\Contract\DB\Driver;
use Decouple\Common\Contract\DB\Schema;
use Decouple\DBAL\Query\Raw;
use Debug\DebugRegistry;
class FrontController {
  public function index(
    Driver $driver,
    Schema $schema,
    DebugRegistry $debug
  ): :xhp {
    $schema = $driver->schema('decouple');
    $articles_table = $schema->table('articles');
    $articles = $articles_table->select(
      Vector {'id', 'title', 'content', 'author_id', 'created_at', 'image'},
    )->where('deleted_at', '=', '0000-00-00 00:00:00')->fetchAll();

    return
      <front:index schema={$schema} title="Decouple">
        <news:articles articles={$articles} />
        {perf_info($debug)}
      </front:index>
    ;
  }

  public function test(): string {
    return "Test";
  }
}
