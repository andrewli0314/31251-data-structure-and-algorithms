const { createGraph } = require('./graph');

describe('Graph', () => {
  let graph;
  beforEach(() => {
    graph = createGraph();
  });

  test('existence', () => {
    expect(graph).toBeDefined();
  });
});
