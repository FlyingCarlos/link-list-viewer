const fs = require("fs");
const protobuf = require("protobufjs");

async function parseDumpedFile() {
  const root = await protobuf.load("proto/node.proto");
  const NodeList = root.lookupType("NodeList");
  const ExecutorMap = root.lookupType("ExecutorMap");
  const nodeListData = fs.readFileSync("build/node_list.bin");
  const executorMapData = fs.readFileSync("build/executor_map.bin");
  const decoded = {
    nodeList: NodeList.decode(nodeListData),
    executorMap: ExecutorMap.decode(executorMapData),
  };
  console.log(decoded.nodeList);
  console.log(decoded.executorMap);
}

// parseDumpedFile();

const data = [
    { value: 1, next: { value: 2, next: { value: 3, next: null } } },
    { value: 4, next: { value: 5, next: null } },
  ];
  
  async function drawLinkedList() {
    const d3 = await import("d3-selection");
  
    const svg = d3.select("body")
      .append("svg")
      .attr("width", 200)
      .attr("height", 200);
  
    const nodes = svg.selectAll("circle")
      .data(data)
      .enter()
      .append("circle")
      .attr("cx", (d, i) => i * 50 + 25)
      .attr("cy", 100)
      .attr("r", 20)
      .style("fill", "white")
      .style("stroke", "black");
  
    const links = svg.selectAll("line")
      .data(data)
      .enter()
      .append("line")
      .attr("x1", (d, i) => i * 50 + 25)
      .attr("y1", 100)
      .attr("x2", (d) => d.next ? (data.indexOf(d.next) * 50 + 25) : 0)
      .attr("y2", 100)
      .style("stroke", "black");
}
  
drawLinkedList();