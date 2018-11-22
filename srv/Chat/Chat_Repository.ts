import { Query, Reply } from 'cqes';
import { Repository }   from 'cqes-db-mysql';

export default new class extends Repository {

  protected resolve(query: Query) {
    switch (query.method) {
    case 'ListUsers': return this.listUsers(query);
    default: return Promise.resolve(new Reply('Bad Query Method'));
    }
  }

  private listUsers(query: Query): Promise<Reply> {
    return new Promise(resolve => {
      const q = 'SELECT `data` FROM `chats` WHERE `key` = ?';
      this.query(q, [query.view], (err: Error, result: Array<any>) => {
        if (err)
          return resolve(new Reply(err.toString()));
        if (result.length == 0)
          return resolve(new Reply(null, []));
        const data = JSON.parse(result[0].data);
        return resolve(new Reply(null, data.users));
      });
    });
  }

}
